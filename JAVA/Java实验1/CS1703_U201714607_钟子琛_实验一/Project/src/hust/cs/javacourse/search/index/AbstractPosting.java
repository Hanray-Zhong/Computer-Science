package hust.cs.javacourse.search.index;

import java.util.ArrayList;
import java.util.List;

/*
AbstractPosting是Posting对象的抽象父类.
 */
public abstract class AbstractPosting
        extends java.lang.Object
        implements java.lang.Comparable<AbstractPosting>, FileSerializable
{
    // 字段
    protected int docId;
    protected int freq;
    protected List<Integer> positions = new ArrayList<>();

    // 构造函数
    public AbstractPosting() { }
    public AbstractPosting(int docId, int freq, java.util.List<java.lang.Integer> positions) {
        this.docId = docId;
        this.freq = freq;
        this.positions = new ArrayList<>(positions);
    }

    // 方法
    public abstract boolean equals(java.lang.Object obj);
    public abstract java.lang.String toString();
    public abstract int getDocId();
    public abstract void setDocId(int docId);
    public abstract int getFreq();
    public abstract void setFreq(int freq);
    public abstract java.util.List<java.lang.Integer> getPositions();
    public abstract void setPositions(java.util.List<java.lang.Integer> positions);
    public abstract int compareTo(AbstractPosting o);
    public abstract void sort();
}
