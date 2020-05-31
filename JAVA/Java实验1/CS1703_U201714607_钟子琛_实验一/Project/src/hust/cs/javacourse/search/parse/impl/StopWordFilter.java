package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.index.impl.TermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleFilter;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;
import hust.cs.javacourse.search.util.StopWords;

import java.io.IOException;

public class StopWordFilter extends AbstractTermTupleFilter {
    public StopWordFilter(AbstractTermTupleStream input) {
        this.input = input;
    }

    @Override
    public AbstractTermTuple next() throws IOException {
        int timer = 0;
        TermTuple termTuple = (TermTuple) input.next();
        while (termTuple != null) {
            timer = 0;
            for (String s : StopWords.STOP_WORDS) {
                if (termTuple.term.getContent().equals(s))
                    break;
                else
                    timer++;
            }
            if (timer == StopWords.STOP_WORDS.length)
                return termTuple;
            else
                termTuple = (TermTuple) input.next();
        }

        return termTuple;
    }
}
