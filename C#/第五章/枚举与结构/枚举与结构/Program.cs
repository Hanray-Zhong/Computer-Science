using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace 枚举与结构
{
    enum orientation : byte
    {
        north=1,
        south=2,
        east=3,
        west=4,
    }
    struct route
    {
        public orientation direction;
        public double distance;
    }
    class Program
    {
        static void Main(string[] args)
        {
            route myRoute;
            int myDirection = -1;
            double myDistance;
            WriteLine("1)North\n2)South\n3)East\n4)West\n");
            do
            {
                WriteLine("Select a direction:");
                myDirection = ToInt32(ReadLine());
            }
            while ((myDirection < 1) || (myDirection > 4));
            WriteLine("Input a distance:");
            myDistance = ToDouble(ReadLine());
            myRoute.direction = (orientation)myDirection;
            myRoute.distance = myDistance;
            WriteLine($"myRoute specifies a direction of {myRoute.direction}" + $" and a distance of {myRoute.distance}");
            ReadKey();
        }
    }
}
