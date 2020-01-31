import java.util.Scanner;
import java.math.BigInteger;

public class AC{
	public static void main(String[] argv){
		Scanner input = new Scanner(System.in);
		int ncase;
		ncase=input.nextInt();
		int N=1;
		while(ncase>0){
			ncase-=1;
			System.out.println(N);
			N++;
			String buf;
			BigInteger a,b;
			buf=input.next();
			if(buf.length()==1 && (buf.charAt(0)=='+' || buf.charAt(0)=='-')){
				String temp=input.next();
				a=new BigInteger(temp);
				temp=input.next();
				b=new BigInteger(temp);
				if(buf.charAt(0)=='+'){
					System.out.println(a.add(b));
				}
				else{
					System.out.println(a.subtract(b));
				}
			}
			else{
				a=new BigInteger(buf);
				buf=input.next();
				b=new BigInteger(buf);
				System.out.println(a.add(b));
			}
		}
	}
}
