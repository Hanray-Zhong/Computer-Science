using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 示例应用程序____card和deck
{
    public class Card
    {
        public readonly Suit suit;
        public readonly Rank rank;//card包含的类（花色和序号）
        public Card(Suit newSuit, Rank newRank)//构造函数
        {
            suit = newSuit;
            rank = newRank;
        }
        private Card()//默认构造函数
        {
        }
        public override string ToString()//重写，使之变为用户理解的文字
        {
            return "The " + rank + " of " + suit + "s";
        }
    }
}
