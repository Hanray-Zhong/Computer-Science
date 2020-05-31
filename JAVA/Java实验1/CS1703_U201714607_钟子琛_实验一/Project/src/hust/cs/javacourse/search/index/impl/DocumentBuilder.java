package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.AbstractDocumentBuilder;
import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;
import hust.cs.javacourse.search.parse.impl.SimpleTupleFilter;
import hust.cs.javacourse.search.parse.impl.StopWordFilter;
import hust.cs.javacourse.search.parse.impl.TermTupleScanner;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class DocumentBuilder extends AbstractDocumentBuilder {

    @Override
    public AbstractDocument build(int docId, String docPath, AbstractTermTupleStream termTupleStream) throws IOException {

        Document document = new Document(docId, docPath);
        TermTuple tempTuple = new TermTuple();

        while ((tempTuple = (TermTuple) termTupleStream.next()) != null) {
            document.addTuple(tempTuple);
        }

        termTupleStream.close();

        return document;
    }

    @Override
    public AbstractDocument build(int docId, String docPath, File file) throws IOException {
        FileReader fileReader = new FileReader(file);
        BufferedReader input = new BufferedReader(fileReader);

        return build(docId, docPath,
                new StopWordFilter(
                new SimpleTupleFilter(
                new TermTupleScanner(input))));
    }
}
