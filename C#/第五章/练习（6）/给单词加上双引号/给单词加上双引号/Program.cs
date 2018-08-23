using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 给单词加上双引号
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Please input a string:");
            string a_string;
            a_string = ReadLine();
            a_string = "\"" + a_string.Replace(" ", "\" \"")+"\"";
            WriteLine($"{a_string}");
            ReadKey();
        }
    }
}
