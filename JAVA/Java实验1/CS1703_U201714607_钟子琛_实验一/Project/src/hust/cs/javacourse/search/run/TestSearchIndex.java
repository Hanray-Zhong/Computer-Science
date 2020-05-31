package hust.cs.javacourse.search.run;

import hust.cs.javacourse.search.index.impl.*;
import hust.cs.javacourse.search.query.AbstractHit;
import hust.cs.javacourse.search.query.impl.Hit;
import hust.cs.javacourse.search.query.impl.IndexSearcher;
import hust.cs.javacourse.search.query.impl.Sorter;

import java.io.IOException;
import java.util.Scanner;

public class TestSearchIndex {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Scanner scanner = new Scanner(System.in);

        IndexSearcher indexSearcher = new IndexSearcher();
        Sorter sorter = new Sorter();

        System.out.println("Input path: ");
        // D:\文档\学习\JAVA\Java实验1\CS1703_U201714607_钟子琛_实验一\真实测试数据集\index.dat  activity and capital
        // D:\文档\学习\JAVA\Java实验1\CS1703_U201714607_钟子琛_实验一\真实测试数据集\index.dat  health and coronavirus
        String path = scanner.nextLine();
        path.replace('\n', '\0');
        indexSearcher.open(path);
        if (indexSearcher.index.getDocSize() != 0)
            System.out.println("Open Index.dat Successfully.");
        else {
            System.out.println("Open Index.dat Failed.");
            return;
        }

        while (true) {
            System.out.println("Input Term: ");
            String Terms = scanner.nextLine();
            String[] TermContents = new String[3];
            Terms.replace('\n', '\0');

            if (Terms.equals("quit!")) {
                return;
            }

            TermContents = Terms.split(" ");
            AbstractHit.LogicalCombination logicalCombination;
            Hit[] hits;
            if (TermContents.length == 1) {
                Term term_1 = new Term(TermContents[0]);
                if (term_1.equals("")) {
                    System.out.println("Input error");
                    continue;
                }
                hits = (Hit[]) indexSearcher.search(term_1, sorter);
            }
            else if (TermContents.length == 3) {
                Term term_1 = new Term(TermContents[0]);
                Term term_2 = new Term(TermContents[2]);
                if (term_1.equals("") || term_2.equals("")) {
                    System.out.println("Input error");
                    continue;
                }
                if (TermContents[1].toLowerCase().equals("and")) {
                    logicalCombination = AbstractHit.LogicalCombination.AND;
                }
                else if (TermContents[1].toLowerCase().equals("or"))
                    logicalCombination = AbstractHit.LogicalCombination.OR;
                else {
                    System.out.println("Input error");
                    continue;
                }
                hits = (Hit[]) indexSearcher.search(term_1, term_2, sorter, logicalCombination);
            }
            else {
                System.out.println("Input error");
                continue;
            }


            if (hits != null && hits.length != 0) {
                for (Hit hit : hits) {
                    System.out.println(hit.toString());
                    System.out.println("\n");
                }
            }
            else
                System.out.println("Not Found Any Doc Including The Term.\n");
        }

    }
}
