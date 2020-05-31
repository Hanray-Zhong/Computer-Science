package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;

public class TermTuple extends AbstractTermTuple {

    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() == TermTuple.class) {
            return term.equals(((TermTuple) obj).term) &&
                    freq == ((TermTuple) obj).freq &&
                    curPos == ((TermTuple) obj).curPos;
        }

        return false;
    }

    @Override
    public String toString() {
        return "term: " + term + " freq: " + freq + " curPos: " + curPos;
    }
}
