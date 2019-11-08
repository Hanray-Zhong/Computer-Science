using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 反转字符串
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Please input a string:");
            string myString;
            myString = ReadLine();
            char[] myWord = myString.ToCharArray();
            string reverseString = "";
            int i;
            for (i=myString.Length-1;i>=0; i--)
            {
                reverseString = reverseString + Convert.ToString(myWord[i]);
            }
            WriteLine($"{reverseString}");
            ReadKey();
        }
    }
}
