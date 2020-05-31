package hust.cs.javacourse.search.query.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;
import hust.cs.javacourse.search.index.AbstractTerm;
import hust.cs.javacourse.search.query.AbstractHit;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Hit extends AbstractHit {
    public Hit() { }
    public Hit(int docId, java.lang.String docPath) {
        this.docId = docId;
        this.docPath = docPath;
    }
    public Hit(int docId, String docPath, Map<AbstractTerm,AbstractPosting> termPostingMapping) {
        this.docId = docId;
        this.docPath = docPath;
        this.termPostingMapping = new HashMap<>(termPostingMapping);
    }

    @Override
    public int getDocId() {
        return docId;
    }

    @Override
    public String getDocPath() {
        return docPath;
    }

    @Override
    public String getContent() {
        return content;
    }

    @Override
    public void setContent(String content) {
        this.content = new String(content);
    }

    @Override
    public double getScore() {
        return score;
    }

    @Override
    public void setScore(double score) {
        this.score = score;
    }

    @Override
    public Map<AbstractTerm, AbstractPosting> getTermPostingMapping() {
        return termPostingMapping;
    }

    @Override
    public String toString() {
        StringBuffer stringBuffer = new StringBuffer();
        stringBuffer.append("DocId: " + docId + "\n");
        stringBuffer.append("DocPath: " + docPath + "\n");
        stringBuffer.append("Content:\n" + content + "\n");

        return stringBuffer.toString();
    }

    @Override
    public int compareTo(AbstractHit o) {
        return (int)(score - o.getScore());
    }
}
