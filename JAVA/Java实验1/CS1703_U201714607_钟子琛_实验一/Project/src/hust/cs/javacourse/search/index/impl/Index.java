package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.*;

import java.io.*;
import java.util.*;

public class Index extends AbstractIndex {

    public Index() {
        docIdToDocPathMapping = new HashMap<>();
        termToPostingListMapping = new HashMap<>();
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append("DocId To DocPath Mapping:\n");
        Iterator<Map.Entry<Integer,String>> iterator_1 = docIdToDocPathMapping.entrySet().iterator();
        while (iterator_1.hasNext()){
            Map.Entry<Integer,String> entry = iterator_1.next();
            stringBuffer.append(entry.getKey() + "\t\t---->\t\t" + entry.getValue()).append("\n");
        }
        stringBuffer.append("Term To PostingList Mapping:\n");
        Iterator<Map.Entry<AbstractTerm, AbstractPostingList>> iterator_2 = termToPostingListMapping.entrySet().iterator();
        while (iterator_2.hasNext()){
            Map.Entry<AbstractTerm, AbstractPostingList> entry = iterator_2.next();
            stringBuffer.append(entry.getKey().toString() + entry.getValue().toString()).append("\n");
        }

        return stringBuffer.toString();
    }

    @Override
    public int getDocSize() {
        return docIdToDocPathMapping.size();
    }

    @Override
    public void addDocument(AbstractDocument document) {
        docIdToDocPathMapping.put(document.getDocId(), document.getDocPath());

        for (AbstractTermTuple termTuple : document.getTuples()) {
            if (!termToPostingListMapping.containsKey(termTuple.term)) {
                termToPostingListMapping.put(termTuple.term, new PostingList());
            }
            PostingList temp_PostingList = (PostingList) termToPostingListMapping.get(termTuple.term);
            Posting temp_Posting = new Posting();
            if (temp_PostingList.size() != 0)
                temp_Posting = (Posting) temp_PostingList.get(temp_PostingList.size() - 1);
            if (temp_PostingList.size() == 0 || temp_Posting.getDocId() != document.getDocId()) {
                temp_PostingList.add(new Posting(document.getDocId(), termTuple.freq, new ArrayList<>()));
                temp_Posting = (Posting) temp_PostingList.get(temp_PostingList.size() - 1);
                temp_Posting.getPositions().add(termTuple.curPos);
            }
            else {
                temp_Posting = (Posting) temp_PostingList.get(temp_PostingList.size() - 1);
                temp_Posting.setFreq(temp_Posting.getFreq() + 1);
                temp_Posting.getPositions().add(termTuple.curPos);
            }
        }
    }

    @Override
    public void load(File file) throws IOException, ClassNotFoundException {
        readObject(new ObjectInputStream(new FileInputStream(file)));
    }

    @Override
    public void save(File file) throws IOException {
        writeObject(new ObjectOutputStream(new FileOutputStream(file)));
    }

    @Override
    public AbstractPostingList search(AbstractTerm term) {
        return termToPostingListMapping.get(term);
    }

    @Override
    public Set<AbstractTerm> getDictionaryKey() {
        return termToPostingListMapping.keySet();
    }

    @Override
    public Map<AbstractTerm,AbstractPostingList> getDictionary() {
        return termToPostingListMapping;
    }

    @Override
    public void optimize() {
        for (AbstractPostingList postingList : termToPostingListMapping.values()) {
            postingList.sort();
            for (AbstractPosting posting : postingList.list) {
                posting.sort();
            }
        }
    }

    @Override
    public String getDocName(int docId) {
        return docIdToDocPathMapping.get(docId);
    }

    @Override
    public void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
        Index temp_index = (Index) in.readObject();
        this.termToPostingListMapping = new HashMap<>(temp_index.termToPostingListMapping);
        this.docIdToDocPathMapping = new HashMap<>(temp_index.docIdToDocPathMapping);
        in.close();
    }

    @Override
    public void writeObject(ObjectOutputStream out) throws IOException {
        Index temp_index = new Index();
        temp_index.termToPostingListMapping = new HashMap<>(termToPostingListMapping);
        temp_index.docIdToDocPathMapping = new HashMap<>(docIdToDocPathMapping);
        out.writeObject(temp_index);
        out.close();
    }
}
