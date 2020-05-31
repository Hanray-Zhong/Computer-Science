package hust.cs.javacourse.search.index;

import java.util.ArrayList;
import java.util.List;

/*
AbstractDocument是文档对象的抽象父类.
 */
public abstract class AbstractDocument
    extends Object
{
    // 字段
    protected int docId;
    protected String docPath = new String();
    protected List<AbstractTermTuple> tuples = new ArrayList<>();

    // 构造函数
    /**
     * 无参构造函数
     * */
    public AbstractDocument() { }
    /**
     * @param docId 文档Id
     * @param docPath 文档路径
     * */
    public AbstractDocument(int docId, String docPath) {
        this.docId = docId;
        this.docPath = docPath;
    }
    /**
     * @param docId 文档Id
     * @param docPath 文档路径
     * @param tuples TermTuple元组
     * */
    AbstractDocument(int docId, String docPath, List<AbstractTermTuple> tuples) {
        this.docId = docId;
        this.docPath = docPath;
        this.tuples = tuples;
    }

    public abstract int getDocId();
    public abstract void setDocId(int docId);
    public abstract String getDocPath();
    public abstract void setDocPath(String docPath);
    public abstract List<AbstractTermTuple> getTuples();
    public abstract void addTuple(AbstractTermTuple tuple);
    public abstract boolean contains(AbstractTermTuple tuple);
    public abstract AbstractTermTuple getTuple(int index);
    public abstract int getTupleSize();
    public abstract String toString();
}
