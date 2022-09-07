int findMinimumCoins(int amount) 
{
   int minCoins = 0;
    while(amount)
    {
        if(amount>=1000)
        {
            minCoins += amount/1000;
            amount = amount%1000;
        }
        if(amount>=500)
        {
            minCoins += amount/500;
            amount = amount%500;
        }
        if(amount>=100)
        {
            minCoins += amount/100;
            amount = amount%100;
        }
        if(amount>=50)
        {
            minCoins += amount/50;
            amount = amount%50;
        }
        
        if(amount>=20)
        {
            minCoins += amount/20;
            amount = amount%20;
        }
        
        if(amount>=10)
        {
            minCoins += amount/10;
            amount = amount%10;
        }
        
        if(amount>=5)
        {
            minCoins += amount/5;
            amount = amount%5;
        }
        
        if(amount>=2)
        {
            minCoins += amount/2;
            amount = amount%2;
        }
        if(amount == 1)
        {
            minCoins += 1;
            amount = amount-1;
        }
    }
    return minCoins;
}
