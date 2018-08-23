using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 变量
{
    class Program
    {
        static void Main(string[] args)
        {
            int myInteger;
            string myString;                                   //在c#中，string是一个变量，而且没有上限。
            myInteger = 17;
            myString = "\"myInteger\" is:";
            Console.WriteLine($"{myString} {myInteger}");      //emmmm暂且不讨论。。
            Console.ReadKey();
        }
    }
}
