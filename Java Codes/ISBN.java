import java.util.*;
public class ISBN
{
    Scanner ob=new Scanner(System.in);
    public int isvalidisbn(String isbn)
    {
        int len=isbn.length();
        if(len!=10)
            return 0;
        double sum=0,digit=0;
        for(int i=0;i<9;i++)
        {
            digit=isbn.charAt(i)-'0';
            if(digit<0 || digit>9)
                return 0;
            sum+=(digit*(10-i));
        }
        char end=isbn.charAt(9);
        if(end!='X' && (end<0 || end>9))
            return 0;
        if(end=='X')
            sum+=10;
        else
            sum+=(end-'0');
        return((sum%11==0)?1:0);
    }
    public void main()
    {
        String isbn;
        System.out.println("Enter ISBN Code :");
        isbn=ob.nextLine();
        if(isvalidisbn(isbn)==1)
            System.out.println("Valid");
        else
            System.out.println("Invalid");
    }
}