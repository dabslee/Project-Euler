import java.text.*;
import java.util.*;

public class PE19 {
	public static void main(String args[]) throws ParseException {
		int numsuns = 0;
		for (int year = 1901; year <= 2000; year++) {
			for (int month = 1; month <= 12; month++) {
				String date = "";
				if (month < 10) date += "0";
				date += Integer.toString(month);
				date += "/01/";
				date += Integer.toString(year);
				
				SimpleDateFormat format1 = new SimpleDateFormat("dd/MM/yyyy");
				Date dt1 = format1.parse(date);
				DateFormat format2 = new SimpleDateFormat("EEEE");
				String finalDay = format2.format(dt1);
				
				if (finalDay.equals("Sunday")) numsuns ++;
			}
		}
		System.out.println(numsuns-1);
	}
}
