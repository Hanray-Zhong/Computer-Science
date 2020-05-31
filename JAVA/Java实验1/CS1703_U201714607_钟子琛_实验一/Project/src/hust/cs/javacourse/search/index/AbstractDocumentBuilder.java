package hust.cs.javacourse.search.index;

import hust.cs.javacourse.search.parse.AbstractTermTupleStream;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

/*
AbstractDocumentBuilder是Document构造器的抽象父类.
 */
public abstract class AbstractDocumentBuilder
    extends Object
{
    // 方法
    public abstract AbstractDocument build(int docId, String docPath, AbstractTermTupleStream termTupleStream) throws IOException;
    public abstract AbstractDocument build(int docId, String docPath, File file) throws IOException;
}
