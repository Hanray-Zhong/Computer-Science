package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.index.impl.TermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleFilter;
import hust.cs.javacourse.search.parse.AbstractTermTupleStream;
import hust.cs.javacourse.search.util.Config;
import hust.cs.javacourse.search.util.StopWords;

import java.io.IOException;

public class SimpleTupleFilter extends AbstractTermTupleFilter {

    public SimpleTupleFilter(AbstractTermTupleStream input) {
        this.input = input;
    }

    @Override
    public AbstractTermTuple next() throws IOException {
        int timer = 0;
        TermTuple termTuple = (TermTuple) input.next();
        while (termTuple != null) {
            if (termTuple.term.getContent().length() >= Config.TERM_FILTER_MINLENGTH &&
                    termTuple.term.getContent().length() <= Config.TERM_FILTER_MAXLENGTH)
                return termTuple;
            else
                termTuple = (TermTuple) input.next();
        }

        return termTuple;
    }
}
