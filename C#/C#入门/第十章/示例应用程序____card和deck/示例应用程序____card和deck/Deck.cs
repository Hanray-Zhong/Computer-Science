using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 示例应用程序____card和deck
{
    public class Deck
    {
        private Card[] cards;//包含的类
        public Deck()//构造函数
        {
            cards = new Card[52];
            for (int suitVal = 0; suitVal < 4; suitVal++)
                for (int rankVal = 1; rankVal < 14; rankVal++)
                {
                    cards[suitVal * 13 + rankVal - 1] = new Card((Suit)suitVal, (Rank)rankVal);
                }//给所有的牌确定花色和序号
        }
        public Card GetCard(int CardNumber)//给用户想要的牌
        {
            if(CardNumber >= 0 && CardNumber <= 51)
            {
                return cards[CardNumber];
            }
            else
            {
                throw (new System.ArgumentOutOfRangeException("cardNumber", CardNumber, "Value must be between 0 and 51"));
            }
        }
        public void Shuffle()//洗牌
        {
            Card[] newDeck = new Card[52];//创建一个新的牌组
            bool[] assigned = new bool[52];//确定该位子是否有牌存在
            Random sourceGen = new Random();
            for(int i = 0; i < 52; i++)
            {
                int destCard = 0;
                bool foundCard = false;
                while(foundCard == false)//这个位子不能放牌
                {
                    destCard = sourceGen.Next(52);//从0~52中选一个随机数给
                    if (assigned[destCard] == false)//这个位子没有牌
                        foundCard = true;//找到了位子可以放一张牌
                }
                assigned[destCard] = true;//这个位子已经有牌了
                newDeck[destCard] = cards[i];//把总牌库里的第i张牌放在这个位子上，接着放第i+1张牌
            }
            newDeck.CopyTo(cards, 0);//将这个新牌库的顺序复制到以前的牌库，即改变了以前的牌库
        }
    }
}
