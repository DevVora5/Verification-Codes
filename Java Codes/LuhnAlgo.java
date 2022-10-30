import java.util.*;
class LuhnAlgo
{
    Scanner ob=new Scanner(System.in);
    public long digitsum(long num)
    {
        long sum=0,digit=0;
        for(int i=0;i<16;i++)
        {
            digit=num%10;
            num=(num/10);
            if(i%2==0)
                sum=sum+digit;
            else
            {
                if(digit*2>8)
                    sum+=((digit*2)%10)+((digit*2)/10);
                else
                    sum=sum+(digit*2);
            }
        }
        return sum;
    }
    public int checkcard(long cardno)
    {
        int len=String.valueOf(cardno).length();
        if(len!=16)
            return 0;
        if(digitsum(cardno)%10==0)
            return 1;
        else
        {
            System.out.println(digitsum(cardno));
            return 0;
        }
    }
    public void main()
    {
        System.out.println("Enter credit card code : ");
        long code=ob.nextLong();
        if(checkcard(code)==1)
            System.out.println("This is a valid card");
        else
            System.out.println("This is an invalid card");
    }
}