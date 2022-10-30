import java.util.*;
public class USPMO
{
    Scanner ob=new Scanner(System.in);
    public long digitsum(long num)
    {
        long sum=0,digit=0;
        num=num/10;
        for(int i=0;i<10;i++)
        {
            digit=num%10;
            num=num/10;
            sum+=digit;
        }
        return sum;
    }
    public int isvaliduspmo(long uspmo)
    {
        int len=String.valueOf(uspmo).length();
        if(len!=11)
            return 0;
        if(digitsum(uspmo)%9==uspmo%10)
            return 1;
        else
            return 0;
    }
    public void main()
    {
        System.out.println("Enter a US postal money order code : ");
        long code=ob.nextLong();
        if(isvaliduspmo(code)==1)
            System.out.println("Valid code");
        else
        {
            System.out.println("Invalid code");
            System.out.println("Possible valid code can be (Only if the last digit is entered incorrectly) : "+(((code/10)*10)+(digitsum(code)%9))+"\n");
        }
    }
}
