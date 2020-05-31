package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractPosting;
import hust.cs.javacourse.search.index.AbstractPostingList;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

public class PostingList extends AbstractPostingList {
    @Override
    public void add(AbstractPosting posting) {
        if (!list.contains(posting))
            list.add(posting);
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("\n");
        for (int i = 0; i < list.size(); i++) {
            buffer.append("\t\t");
            buffer.append("[" + list.get(i) + "]\n");
        }

        return buffer.toString();
    }

    @Override
    public void add(List<AbstractPosting> postings) {
        for (AbstractPosting item : postings) {
            add(item);
        }
    }

    @Override
    public AbstractPosting get(int index) {
        return list.get(index);
    }

    @Override
    public int indexOf(AbstractPosting posting) {
        return list.indexOf(posting);
    }

    @Override
    public int indexOf(int docId) {
        for (AbstractPosting item : list) {
            if (item.getDocId() == docId)
                return list.indexOf(item);
        }
        return -1;
    }

    @Override
    public boolean contains(AbstractPosting posting) {
        return list.contains(posting);
    }

    @Override
    public void remove(int index) {
        list.remove(index);
    }

    @Override
    public void remove(AbstractPosting posting) {
        list.remove(posting);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public void clear() {
        list.clear();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void sort() {
        Collections.sort(list);
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
