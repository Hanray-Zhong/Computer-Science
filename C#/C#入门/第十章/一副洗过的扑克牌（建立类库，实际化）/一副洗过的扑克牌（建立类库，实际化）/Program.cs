using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using 示例应用程序____card和deck;

namespace 一副洗过的扑克牌_建立类库_实际化_
{
    class Program
    {
        static void Main(string[] args)
        {
            Deck myDeck = new Deck();
            myDeck.Shuffle();
            for(int i = 0; i < 52; i++)
            {
                Card tempCard = myDeck.GetCard(i);
                WriteLine(tempCard.ToString());
            }
            ReadKey();
        }
        
    }
}
