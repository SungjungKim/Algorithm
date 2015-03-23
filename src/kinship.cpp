/*
*	�̼� ���(degree of kinship)
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*
������ ���� Ȥ�� ģô�� ������ ���踦 ��Ÿ���� �̼��� ����ϴµ� ���ϴ�. �̼��� �⺻������ �θ�� �ڽ� ���̸� 1������ �����ϰ� �̷κ��� ����� ���� �̼��� ����ϰ� �ȴ�.
���� ��� ���� �ƹ���, �ƹ����� �Ҿƹ����� ���� 1���̹Ƿ� ���� �Ҿƹ����� 2���� �ǰ�, �ƹ��� ������� �Ҿƹ����� 1���̹Ƿ� ���� �ƹ����� ��������� 3���� �ȴ�.
������ ���� ����鿡 ���� �θ� �ڽĵ� ���� ���谡 �־��� ���� ��, �־��� �� ����� �̼��� ����ϴ� ���α׷��� ������� �Ѵ�.

Input
���� testcase�� ��Ÿ���� N�� �־�����. �������� �־����� ������ testcase������ ������ ����.
- ù��°�� ��ü����� �� n(1<=n<=100)�� �־�����.
- �ι�°�� �̼��� ����ؾ� �ϴ� ���� �ٸ� �� ����� ��ȣ�� �־�����.
- ����°���� �θ� �ڽĵ� ���� ������ ������ �־�����.
-�� �������� �θ� �ڽİ��� ���踦 ��Ÿ���� �� ���� �־�����. �̶� �տ� ������ ��ȣ x�� �ڿ� ������ ���� y�� �θ��ȣ�� ��Ÿ����.

Output
�Է¿��� �䱸�� �� ����� �̼��� ��Ÿ���� ������ ����Ѵ�. �λ������ ģô���谡 �ƴҽ� -1�� ����Ѵ�.

Input sample
2
9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
9
8 6
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6

Output sample
#testcase1
3
#testcase2
-1

*/

/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;

/*
struct Person.

- index : index of person.
- *parent : pointer of parent.
*/
typedef struct _person {
	int index;
	struct _person *parent;
}Person;

/*
Create person array.

Array : {person01, person02, person03, .... }
*/
Person* initPerson(int num_people) {
	Person pArray[100];

	for (int i = 0; i < num_people; i++) {
		Person person;
		person.index = i + 1;
		person.parent = NULL;	

		pArray[i] = person;
	}
	
	return pArray;
}


/*
Initialize relation between each person.
*/
//Person** initRelation(Person** person, int num_relation) {
//	int index01, index02;	// index of person
//
//	for (int i = 0; i < num_relation; i++) {
//		cin >> index01 >> index02;
//
//		
//	}
//}

void testLink(Person* person, int num_people) {
	for (int i = 0; i < num_people - 1; i++) {
		person[i].parent = &person[i+1];
	}

	for (int i = 0; i < num_people - 1; i++) {
		cout << person[i].index << " ";
	}
	cout << endl;
}


int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		�˰����� ���� �κ�

		*/

		int num_people;		// num of people
		int target01, target02;		// people who calculated degree of kinship
		int num_relation;	// num of relation
		Person* person;

		cin >> num_people;
		cin >> target01 >> target02;
		cin >> num_relation;

		person = initPerson(num_people);
		testLink(person, num_people);
		//initRelation(num_relation);
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}