using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.ValueTuple;
using System.IO;
using Essential_CS.Chapter7;
using Essential_CS.Chapter14;
using Essential_CS.Chapter15;
using Essential_CS.Chapter17;


namespace Essential_CS
{
    // chapter 14
    #region
    /*
    class Program {
        static void Main(string[] args) {
            Thermostat thermostat = new Thermostat();
            Cooler cooler = new Cooler(60);
            Heater heater = new Heater(80);

            string temperature;

            // 注册订阅者
            thermostat.OnTemperatureChange += cooler.OnTemperatureChanged;
            thermostat.OnTemperatureChange += heater.OnTemperatureChanged;

            Write("Enter temperature : ");
            temperature = ReadLine();
            thermostat.CurrentTemperature = int.Parse(temperature);
            ReadLine();
        }
    }
    */
    #endregion

    // chapter 15
    #region
    /*
    class Program {
        static void Main(string[] args) {
            IEnumerable<Patent> patents = PatentData.Patents;
            // 1、Where() 筛选
            IEnumerable<Patent> patentsOf1800 = patents.Where(patent => patent.YearOfPublication.StartsWith("18"));

            // 2、Select 投射
            // 输出虽然相同，但是针对每个数据项都会发生一次转换
            IEnumerable<string> items_1 = patentsOf1800.Select(patent => patent.ToString());
            // 如下例，将 string 集合投射为元组集合
            
            // IEnumerable<string> fileList = Directory.EnumerateFiles("RootPath", "SearchPath");
            // IEnumerable<(string FileName, long Size)> items_2 = fileList.Select(
            //     file => {
            //         FileInfo fileinfo = new FileInfo(file);
            //         return (FileName: fileinfo.Name, Size: fileinfo.Length);
            //     }
            // );
            

            Print<Patent>(patents);

            WriteLine();

            IEnumerable<Inventor> inventors = PatentData.Inventors;
            Print(inventors);

            WriteLine();

            // 3、Count 计数
            WriteLine($"Patent Count: {patents.Count()}");
            WriteLine($"Patent Count in 1800s: {patents.Count(patent => patent.YearOfPublication.StartsWith("18"))}");
            // 检查集合中是否存在项时，使用 Any()，而不是判断 Count() > 0
            if (patents.Any()) {
                // code
            }

            WriteLine();

            // 4、推迟执行
            bool result;
            IEnumerable<Patent> _patents = patents;
            _patents = _patents.Where(
                _patent => {
                    if (result = _patent.YearOfPublication.StartsWith("18")) {
                        WriteLine("\t" + _patent);
                    }
                    return result;
                }
            );
            // 第一次：foreach
            WriteLine("1. ");
            foreach (Patent _patent in _patents) {

            }
            WriteLine();
            // 第二次：Count
            WriteLine("2.");
            WriteLine($"There are {_patents.Count()} patents prior in 1900s");
            WriteLine();
            // 第三次：ToXXX
            WriteLine("3.");
            _patents = _patents.ToArray();
            // 现在调用 Count 就不会执行委托了
            WriteLine($"There are {_patents.Count()} patents prior in 1900s");

            ReadKey();
        }

        private static void Print<T>(IEnumerable<T> items) {
            foreach (T item in items) {
                WriteLine(item.ToString());
            }
        }
    }
    */
    #endregion

    // chapter 16 查询表达式
    #region
    /*
    class Program
    {
        static void Main(string[] args) {

        }
    }
    */
    #endregion

    // chapter 17
    #region
    class Program
    {
        static void Main(string[] args) {
            #region BinarySearch() 的结果进行按位取反
            /*
            // 对 BinarySearch() 的结果进行按位取反
            List<string> list = new List<string>();
            int search;

            list.Add("Public");
            list.Add("Protected");
            list.Add("Private");

            list.Sort();

            search = list.BinarySearch("Protected internal");
            if (search < 0) {
                // 按位取反，找到大于被查找元素的下一个元素，可以方便插入新值
                list.Insert(~search, "Protected internal");
            }
            foreach (string accessModifier in list) {
                WriteLine(accessModifier);
            }
            ReadKey();
            */
            #endregion

            #region Dictionary<TKey, TValue>
            /*
            var colorMap = new Dictionary<string, ConsoleColor> {
                ["Error"] = ConsoleColor.Red,
                ["Warning"] = ConsoleColor.Yellow,
                ["Information"] = ConsoleColor.Green,
            };
            // Add  *删除旧值ConsoleColor.red，将Cyan与键关联
            colorMap.Add("Error", ConsoleColor.Cyan);
            // 索引器
            colorMap["Verbose"] = ConsoleColor.White;
            // foreach遍历  *KeyValuePair
            foreach (KeyValuePair<string, ConsoleColor> item in colorMap) {
                WriteLine(item.Key);
            }
            */
            #endregion

            #region Stack<T>, Queue<T>, LinkedList<T>

            #endregion

            #region indexer
            /*
            MyIndexer.Pair<int> pair = new MyIndexer.Pair<int>(1, 2);
            // 索引器使用
            WriteLine(pair[MyIndexer.PairItem.First]);
            */
            #endregion

            #region 迭代器
            var keywords = new CSharpBuiltInTypes();
            foreach (string keyword in keywords) {
                WriteLine(keyword);
            }
            #endregion
        }
    }
    #endregion
}
