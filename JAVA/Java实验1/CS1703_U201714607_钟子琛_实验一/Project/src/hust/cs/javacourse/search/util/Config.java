package hust.cs.javacourse.search.util;

/*
保存搜索引擎的配置信息，
例如：   索引文件所在目录
        要建立索引的文本文件所在目录
        构建索引时是否忽略单词大小写
        分词所需要的正则表达式
        基于正则表达式的三元组过滤器所需的正则表达式
        基于单词长度的三元组过滤器所需的最小单词长度和最大单词长度 ...
 */
public class Config extends Object {
    public static java.lang.String PROJECT_HOME_DIR;
    public static java.lang.String INDEX_DIR;
    public static java.lang.String DOC_DIR;
    public static boolean IGNORE_CASE;
    public static java.lang.String STRING_SPLITTER_REGEX = "[,|，|;|；|.|。|?|？|：|:|!|！|\\s|\"]+";
    public static java.lang.String TERM_FILTER_PATTERN;
    public static int TERM_FILTER_MINLENGTH = 3;
    public static int TERM_FILTER_MAXLENGTH = 20;
}
