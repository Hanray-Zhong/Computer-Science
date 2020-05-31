package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.AbstractTermTuple;

import java.util.List;

public class Document extends AbstractDocument {

    /**
     * 无参构造函数
     * */
    public Document() { }
    /**
     * 含参构造函数
     * @param docId 文档Id
     * @param docPath 文档路径
     * */
    public Document(int docId, String docPath) {
        this.docId = docId;
        this.docPath = docPath;
    }
    /**
     * @param docId 文档Id
     * @param docPath 文档路径
     * @param tuples TermTuple元组
     * */
    Document(int docId, String docPath, List<AbstractTermTuple> tuples) {
        this.docId = docId;
        this.docPath = docPath;
        this.tuples = tuples;
    }

    /**
     * 获取文档Id
     * @return DocId
     * */
    @Override
    public int getDocId() {
        return docId;
    }

    /**
     * 设置文档Id
     * @param docId DocId
     * */
    @Override
    public void setDocId(int docId) {
        this.docId = docId;
    }

    /**
     * 获取文档路径
     * @return DocPath
     * */
    @Override
    public String getDocPath() {
        return docPath;
    }

    /**
     * 设置文档路径
     * @param docPath DocPath
     * */
    @Override
    public void setDocPath(String docPath) {
        this.docPath = docPath;
    }

    /**
     * 获得Term元组
     * */
    @Override
    public List<AbstractTermTuple> getTuples() {
        return tuples;
    }

    /**
     * 增加新的Term元组
     * */
    @Override
    public void addTuple(AbstractTermTuple tuple) {
        this.tuples.add(tuple);
    }

    /**
     * 判断是否包含该元组
     * @param tuple Term元组
     * */
    @Override
    public boolean contains(AbstractTermTuple tuple) {
        return this.tuples.contains(tuple);
    }

    /**
     * 获得对应序号的元组
     * @param index 序号
     * */
    @Override
    public AbstractTermTuple getTuple(int index) {
        return this.tuples.get(index);
    }

    /**
     * 获得整个元组列表的大小
     * */
    @Override
    public int getTupleSize() {
        return this.tuples.size();
    }

    @Override
    public String toString() {
        return "docId: " + docId + " docPath: " + docPath + "\ntuples: " + tuples;
    }
}
