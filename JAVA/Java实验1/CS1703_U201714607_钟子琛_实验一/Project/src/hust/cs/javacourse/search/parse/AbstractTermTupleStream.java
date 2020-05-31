package hust.cs.javacourse.search.parse;

import hust.cs.javacourse.search.index.AbstractTermTuple;

import java.io.IOException;

/*
AbstractTermTupleStream是各种TermFreqPosTupleStream对象的抽象父类
TermFreqPosTupleStream是三元组TermTuple流对象，
包含了解析文本文件得到的三元组序列
 */
public abstract class AbstractTermTupleStream extends Object
{
    public abstract AbstractTermTuple next() throws IOException;
    public abstract void close() throws IOException;
}
