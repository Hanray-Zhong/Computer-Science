using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 传参
{
    class Program
    {
        static void showdouble(ref int val)       //ref使形式参数直接为实际参数，在函数中改变的值也会直接改变实际的值
        {
            val *= 2;
            WriteLine($"double val = {val}");
        }
        static void Main(string[] args)
        {
            int number = 5;
            WriteLine($"mynumber = {number}");
            showdouble(ref number);
            WriteLine($"mynumber = {number}");
            ReadKey();
        }
    }
}
