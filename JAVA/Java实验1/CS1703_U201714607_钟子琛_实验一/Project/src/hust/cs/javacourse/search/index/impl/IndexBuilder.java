package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractDocumentBuilder;
import hust.cs.javacourse.search.index.AbstractIndex;
import hust.cs.javacourse.search.index.AbstractIndexBuilder;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class IndexBuilder extends AbstractIndexBuilder {
    public IndexBuilder(AbstractDocumentBuilder docBuilder) {
        this.docBuilder = docBuilder;
    }

    @Override
    public AbstractIndex buildIndex(String rootDirectory) throws IOException {
        Index index = new Index();

        File file = new File(rootDirectory);
        File[] tempList = file.listFiles();

        for (int i = 0; i < tempList.length; i++) {
            if (tempList[i].isFile() && tempList[i].toString().endsWith(".txt")) {
                // 判断是文本文件，docId 加 1
                index.addDocument(docBuilder.build(docId, tempList[i].getPath(), tempList[i]));
                docId++;
            }
        }
        index.save(new File(rootDirectory + "/index.dat"));
        return index;
    }
}
