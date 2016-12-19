import java.util.Scanner;
public class Test
{
	int a, luas;
	public static void main(String[] args)
	{
		Scanner scan = new Scanner (System.in);
		System.out.print("Input sisi:	");
		a= scan.nextInt();

		luas = a*a;
		System.out.print("Luas"+luas);
	}
}
