package Java;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {


		ArrayList<Element> element = new ArrayList<Element>();
		
		element.add(new Person(34, "Maria Gina"));
		element.add(new Person(56, "Costel Marian"));
		element.add(new Building(4, "White House"));
		element.add(new Building(100, "La Rocca"));
		element.add(new Person(36, "Cornelia Geanina"));
		element.add(new Building(4, "Greeny"));
		element.add(new Person(73, "Alina Mirela"));
		element.add(new Building(10, "Fly High"));
		
		
		
		ArrayList<Element> greater = new ArrayList<Element>();
		Element elem = new Element();
		Scanner input = new Scanner(System.in);
		int swt = 1;
		elem.PrintPerson(element);
		elem.PrintBuildings(element);
		/*Menu*/
		System.out.println("Choose your option: ");
		System.out.println("1. The oldest element in the array");
		System.out.println("2. The oldest person: ");
		System.out.println("3. The oldest building: ");
		System.out.println("4. All persons greater than a max value: ");
		System.out.println("5. Buildings older than a max value: ");
		System.out.println("6. Elements older than max value");
		while(swt > 0 && swt< 7){
			swt = input.nextInt();
			switch(swt){
			
			case 1: 
			
				Element oldestElement = elem.TheOldestElem(element);
				System.out.println("Your choice was 1");
				System.out.println("the oldest element in the list is " + oldestElement.name + " age: " + oldestElement.age);
				break;
			
			case 2:
			
				Element oldestPerson = elem.TheOldestPerson(element);
				System.out.println("Your choice was 2");
				System.out.println("the oldest person in the list is " + oldestPerson.name + " age: " + oldestPerson.age);
				break;
			
			case 3:
			
				Element oldestBuilding = elem.TheOldestBuilding(element);
				System.out.println("Your choice was 3");
				System.out.println("the oldest building in the list is " + oldestBuilding.name + " age: " + oldestBuilding.age);
				break;
		
			case 4: 
				int maxAgePerson = 30;
			
				greater = elem.PersonGreaterThanMax(element, maxAgePerson);
				
				System.out.println("Your choice was 4");
				System.out.println("Persons older than " + maxAgePerson +" :");
				for(Element it:greater)
					System.out.println(it);
				break;
				
			case 5: 
				int maxAgeBuilding = 5;
				
				greater = elem.BuildingsGreaterThanMax(element, maxAgeBuilding);
				System.out.println("Your choice was 5");
				System.out.println("Buildings older than " + maxAgeBuilding +" :");
				for(Element it:greater)
					System.out.println(it);
				break;
			
			case 6: 
				int maxAgeElement = 30;
		
				greater = elem.GreaterThanMax(element, maxAgeElement);
				System.out.println("Your choice was 6");
				System.out.println("Elements older than " + maxAgeElement +" :");
				for(Element it:greater)
					System.out.println(it);
				break;
				
			case 7:
				System.out.println("Exit");
				break;
		}
				
		
		}
	}

}
