using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 作用域
{
    class Program
    {
        static string myString;
        static void Write()
        {
            string myString = "string defined in function.";
            WriteLine($"In Write():\nmyString = {myString}");
            WriteLine($"Global myString = {Program.myString}");     //用Program.__来访问
        }
        static void Main(string[] args)
        {
            string myString = "string defined in main.";
            Program.myString = "Global string.";
            Write();
            WriteLine($"In main:\nmyString = {myString}");
            WriteLine($"Global myString = {Program.myString}");
            ReadKey();
        }
    }
}
