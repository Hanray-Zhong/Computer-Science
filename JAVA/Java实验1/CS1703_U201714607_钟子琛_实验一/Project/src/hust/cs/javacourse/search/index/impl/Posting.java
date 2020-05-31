package hust.cs.javacourse.search.index.impl;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;
import hust.cs.javacourse.search.index.AbstractPosting;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Posting extends AbstractPosting {
    public Posting() { }
    public Posting(int docId, int freq, List<Integer> positions) {
        this.docId = docId;
        this.freq = freq;
        this.positions = new ArrayList<>(positions);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() == Posting.class)
            return docId == ((Posting) obj).docId &&
                    freq == ((Posting) obj).freq &&
                    positions.equals(((Posting) obj).positions);
        return false;
    }

    @Override
    public String toString() {
        return "docId: " + docId + " freq: " + freq + " positions: " + positions;
    }

    @Override
    public int getDocId() {
        return docId;
    }

    @Override
    public void setDocId(int docId) {
        this.docId = docId;
    }

    @Override
    public int getFreq() {
        return freq;
    }

    @Override
    public void setFreq(int freq) {
        this.freq = freq;
    }

    @Override
    public List<Integer> getPositions() {
        return positions;
    }

    @Override
    public void setPositions(List<Integer> positions) {
        this.positions = new ArrayList<>(positions);
    }

    @Override
    public int compareTo(AbstractPosting o) {
        return docId - o.getDocId();
    }


    @Override
    public void sort() {
        Collections.sort(positions);
    }

    @Override
    public void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
        in.readObject();
        in.close();
    }

    @Override
    public void writeObject(ObjectOutputStream out) throws IOException {
        out.writeObject(this);
        out.close();
    }
}
