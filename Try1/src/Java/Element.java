package Java;
import java.util.*;
public class Element{
	int age;
	String name;
	
	
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public int TheOldest(ArrayList<Element> list){
		
		int maxAge = 0;
		for(Element it : list){
			if(it.getAge() > maxAge)
				maxAge = it.getAge() ;
		}
		return maxAge; 
	}
	
	public Element TheOldestElem(ArrayList<Element> list){
		
		Element maxAge = new Element();
		for(Element it : list){
			
			if(maxAge == null)
				maxAge = it;
			else if(it.getAge() > maxAge.getAge())
				maxAge = it ;
		}
		return maxAge; 
	}
	

	public ArrayList<Element> GreaterThanMax(ArrayList<Element> list,  int max) {
		ArrayList<Element> personGreaterThan = new ArrayList<Element>();
		for(Element it : list){
			if(it.getAge() > max)
				personGreaterThan.add(it);
		}
		
		return personGreaterThan;
	}
	
	public ArrayList<Element> PersonGreaterThanMax(ArrayList<Element> list,  int max) {
		ArrayList<Element> personGreaterThan = new ArrayList<Element>();
		for(Element it : list){
			if(it instanceof Person && it.getAge() > max)
				personGreaterThan.add(it);
		}
		
		return personGreaterThan;
	}
	
	public ArrayList<Element> BuildingsGreaterThanMax(ArrayList<Element> list,  int max) {
		ArrayList<Element> personGreaterThan = new ArrayList<Element>();
		for(Element it : list){
			if(it instanceof Building && it.getAge() > max)
				personGreaterThan.add(it);
		}
		
		return personGreaterThan;
	}
	
	public Element TheOldestPerson(ArrayList<Element> list)
	{
		Element oldestPerson = new Element();
		
		for(Element it:list)
		{
			if(it instanceof Person)
			{
				if(oldestPerson == null){
					oldestPerson = it;
				}
				else if(it.age>oldestPerson.age){
					oldestPerson=it;
				}
			}
		}
		return oldestPerson;
	}
	
	public Element TheOldestBuilding(ArrayList<Element> list){
		Element oldestBuilding = new Element();
		
		for(Element it : list){
			if(it instanceof Building){
				if(oldestBuilding  == null){
					oldestBuilding = it;
				}
				else if(it.age > oldestBuilding.age){
					oldestBuilding = it;
				}
			}
			
		}
		
		return oldestBuilding;
		
}
	
	public void Print(ArrayList<Element> list){
		
		for(Element it: list){
			System.out.println(it);
		}
		
	}
	public void PrintPerson(ArrayList<Element> list){
		
		for(Element it: list){
			if(it instanceof Person){
				System.out.println(it);
			}
		}
		
	}
	

	public void PrintBuildings(ArrayList<Element> list){
		
		for(Element it: list){
			if(it instanceof Building){
				System.out.println(it);
			}
		}
		
	}
}
