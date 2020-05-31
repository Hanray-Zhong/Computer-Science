package hust.cs.javacourse.search.parse.impl;

import hust.cs.javacourse.search.index.AbstractTermTuple;
import hust.cs.javacourse.search.index.impl.TermTuple;
import hust.cs.javacourse.search.parse.AbstractTermTupleScanner;
import hust.cs.javacourse.search.util.Config;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TermTupleScanner extends AbstractTermTupleScanner {
    List<String> input_Strings = new ArrayList<>();
    String line = new String();
    int curPos = 1;

    // 构造方法
    public TermTupleScanner() { }
    // 分词
    public TermTupleScanner(BufferedReader input) throws IOException {
        this.input = input;
        while ((line = input.readLine()) != null) {
            String[]  array_string = line.split(Config.STRING_SPLITTER_REGEX);
            for (String s : array_string) {
                if (s.equals(""))
                    continue;
                input_Strings.add(s);
            }
        }
    }

    @Override
    public AbstractTermTuple next() throws IOException {
        TermTuple termTuple = new TermTuple();
        if (input_Strings.size() != 0) {
            termTuple.term.setContent(input_Strings.get(0));
            termTuple.curPos = curPos;
            curPos++;
            input_Strings.remove(0);
        }
        else
            termTuple = null;

        return termTuple;
    }
}
