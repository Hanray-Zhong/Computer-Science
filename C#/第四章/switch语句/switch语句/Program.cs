using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace switch语句
{
    class Program
    {
        static void Main(string[] args)
        {
            const string myname = "benjamin";
            const string nicename = "andrea";
            const string sillyname = "ploppy";
            string name;
            WriteLine("What's your name?");
            name = ReadLine();                  //ReadLine()函数读取的是字符串，这里不需要转化
            switch (name.ToLower)               //string.Tolower可以把该字符串的所有大写转化成小写
            {
                case "benjamin":WriteLine("You have the same name of me!");break;
                case "andrea":WriteLine("What a nice name you have!");break;
                case "ploppy":WriteLine("That's a very silly name.");break;
            }
            WriteLine($"Hello! {name}!");
            ReadKey();

        }
    }
}
