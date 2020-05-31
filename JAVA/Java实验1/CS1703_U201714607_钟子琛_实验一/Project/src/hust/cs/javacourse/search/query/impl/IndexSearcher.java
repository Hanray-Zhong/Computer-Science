package hust.cs.javacourse.search.query.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;
import hust.cs.javacourse.search.index.AbstractTerm;
import hust.cs.javacourse.search.index.impl.PostingList;
import hust.cs.javacourse.search.index.impl.Term;
import hust.cs.javacourse.search.query.AbstractHit;
import hust.cs.javacourse.search.query.AbstractIndexSearcher;
import hust.cs.javacourse.search.query.Sort;
import hust.cs.javacourse.search.util.FileUtil;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class IndexSearcher extends AbstractIndexSearcher {
    @Override
    public void open(String indexFile) throws IOException, ClassNotFoundException {
        File file = new File(indexFile);
        if (file.isFile())
            index.load(file);
        else return;
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm, Sort sorter) {
        if (index == null)
            return null;

        // 够建DIC
        Map<AbstractTerm, AbstractPostingList> dic = index.getDictionary();

        Hit[] result_hit = new Hit[0];

        if (dic.containsKey(queryTerm)) {
            int i = 0;
            result_hit = new Hit[dic.get(queryTerm).list.size()];

            for (AbstractPosting posting : dic.get(queryTerm).list) {
                Map<AbstractTerm, AbstractPosting> tempMap = new HashMap<>();
                tempMap.put(queryTerm, posting);
                result_hit[i] = new Hit(posting.getDocId(), index.getDocName(posting.getDocId()), tempMap);

                result_hit[i].setContent(FileUtil.read(index.getDocName(posting.getDocId())));
                result_hit[i].setScore(sorter.score(result_hit[i]));
                i++;
            }
        }
        else {
            result_hit = null;
        }


        return result_hit;
    }

    @Override
    public AbstractHit[] search(AbstractTerm queryTerm1, AbstractTerm queryTerm2, Sort sorter, AbstractHit.LogicalCombination combine) {
        if (index == null)
            return null;

        // 够建 DIC
        Map<AbstractTerm, AbstractPostingList> dic = index.getDictionary();

        // 结果
        Hit[] result_hit;
        // 用来暂时存储hit的list，之后进行过滤
        List<Hit> temp_HitList_1 = new ArrayList<>();
        List<Hit> temp_HitList_2 = new ArrayList<>();
        // 存储文档个数
        int[] docIds = new int[index.getDocSize()];
        int[] existDocId = new int[index.getDocSize()];


        if (dic.containsKey(queryTerm1) || dic.containsKey(queryTerm2)) {
            int i = 0;
            // 处理 Term1
            if (dic.containsKey(queryTerm1)) {
                for (AbstractPosting posting : dic.get(queryTerm1).list) {
                    Map<AbstractTerm, AbstractPosting> tempMap = new HashMap<>();
                    tempMap.put(queryTerm1, posting);
                    temp_HitList_1.add(new Hit(posting.getDocId(), index.getDocName(posting.getDocId()), tempMap));
                    docIds[posting.getDocId() - 1]++;

                    temp_HitList_1.get(i).setContent(FileUtil.read(index.getDocName(posting.getDocId())));
                    temp_HitList_1.get(i).setScore(sorter.score(temp_HitList_1.get(i)));
                    i++;
                }
            }
            // 处理 Term2
            if (dic.containsKey(queryTerm2)) {
                for (AbstractPosting posting : dic.get(queryTerm2).list) {
                    Map<AbstractTerm, AbstractPosting> tempMap = new HashMap<>();
                    tempMap.put(queryTerm2, posting);
                    temp_HitList_1.add(new Hit(posting.getDocId(), index.getDocName(posting.getDocId()), tempMap));
                    docIds[posting.getDocId() - 1]++;

                    temp_HitList_1.get(i).setContent(FileUtil.read(index.getDocName(posting.getDocId())));
                    temp_HitList_1.get(i).setScore(sorter.score(temp_HitList_1.get(i)));
                    i++;
                }
            }

            // 如果查找内容为 AND，整理 List，删除doc出现次数不足两次的内容
            if (combine == AbstractHit.LogicalCombination.AND) {
                int temp_docId;
                for (; i > 0; i--) {
                    temp_docId = temp_HitList_1.get(i - 1).getDocId() - 1;
                    if (docIds[temp_docId] < 2) {
                        temp_HitList_1.remove(i - 1);
                    }
                }
            }
            // 删除重复文档
            for (Hit hit :temp_HitList_1) {
                if (existDocId[hit.getDocId() - 1] >= 1)
                    continue;
                else {
                    temp_HitList_2.add(hit);
                    existDocId[hit.getDocId() - 1]++;
                }
            }
            // 将 temp_HitList 录入 result_hit
            result_hit = new Hit[temp_HitList_2.size()];
            i = 0;
            for (Hit hit: temp_HitList_2) {
                result_hit[i] = hit;
                i++;
            }
        }
        else {
            result_hit = null;
        }

        return result_hit;
    }
}
