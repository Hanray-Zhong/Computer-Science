package hust.cs.javacourse.search.query;

import hust.cs.javacourse.search.index.*;

import java.util.HashMap;
import java.util.Map;

public abstract class AbstractHit extends Object implements Comparable<AbstractHit>
{
    public static enum LogicalCombination {
        AND, OR,
    }

    protected int docId;
    protected String docPath = new String();
    protected String content = new String();
    protected Map<AbstractTerm, AbstractPosting> termPostingMapping = new HashMap<>();
    protected double score = 1.0;

    public AbstractHit() { }
    public AbstractHit(int docId, java.lang.String docPath) {
        this.docId = docId;
        this.docPath = docPath;
    }
    public AbstractHit(int docId, String docPath, Map<AbstractTerm,AbstractPosting> termPostingMapping) {
        this.docId = docId;
        this.docPath = docPath;
        this.termPostingMapping = termPostingMapping;
    }

    public abstract int getDocId();
    public abstract String getDocPath();
    public abstract String getContent();
    public abstract void setContent(java.lang.String content);
    public abstract double getScore();
    public abstract void setScore(double score);
    public abstract Map<AbstractTerm,AbstractPosting> getTermPostingMapping();
    public abstract String toString();
    public abstract int compareTo(AbstractHit o);

}
