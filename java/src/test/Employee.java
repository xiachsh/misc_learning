package test;
import java.io.*;

public class Employee 
{
	String name;
	int age;
	String designation;
	double salary;
	public Employee(String name)
	{
		this.name = name;
	}	
	public void empAge(int empAge)
	{	
		age = empAge;
	}
	public void empDesignation(String empDesignation)
	{
		designation = empDesignation;
	}
	public void empSalary(double empSalary)
	{
		salary = empSalary;
	}
	public void printEmployee()
	{
		System.out.println("Name:" + name);
		System.out.println("Age:" + age);
		System.out.println("Designation:" + designation);
		System.out.println("Salary:" + salary);
	}
	public static void main(String[] args)
	{
		Employee empOne = new Employee("James Smith");
		Employee empTwo = new Employee("Mary Anne");
		
		empOne.empAge(26);
		empOne.empDesignation("Software Engineer");
		empOne.empSalary(1100);
		empOne.printEmployee();

		empTwo.empAge(30);
		empTwo.empDesignation("Senior Software Engineer");
		empTwo.empSalary(3000);
		empTwo.printEmployee();
		
	}
}
