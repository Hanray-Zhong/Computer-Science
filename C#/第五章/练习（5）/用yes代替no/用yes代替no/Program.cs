using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 用yes代替no
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Please input a string:");
            string a_string;
            a_string = ReadLine();
            char[] character = a_string.ToCharArray();
            string string_result="";
            int i ;
            for (i = 0; i < a_string.Length; i++)
            {
                if (character[i] == 'n' || character[i + 1] == 'o')
                {
                    string_result += "yes";
                    i++;
                }
                else
                    string_result += Convert.ToString(character[i]);
            }
            WriteLine($"{string_result}");
            ReadKey();
        }
    }
}
