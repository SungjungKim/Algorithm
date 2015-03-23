/*
*	촌수 계산(degree of kinship)
*
*	Kookmin University
*	Computer Science Department
*	20103310 Sungjung Kim
*
*/

/*
병수는 가족 혹은 친척들 사이의 관계를 나타내는 촌수를 계산하는데 약하다. 촌수는 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산하게 된다.
예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌이므로 나와 할아버지는 2촌이 되고, 아버지 형제들과 할아버지는 1촌이므로 나와 아버지의 형제들과는 3촌이 된다.
병수는 여러 사람들에 대한 부모 자식들 간의 관계가 주어져 있을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 만들고자 한다.

Input
먼저 testcase를 나타내는 N이 주어진다. 다음부터 주어지는 각각의 testcase조건은 다음과 같다.
- 첫번째로 전체사람의 수 n(1<=n<=100)이 주어진다.
- 두번째는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다.
- 세번째줄은 부모 자식들 간의 관계의 개수가 주어진다.
-이 다음부터 부모 자식간의 관계를 나타내는 두 값이 주어진다. 이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모번호를 나타낸다.

Output
입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 두사람간의 친척관계가 아닐시 -1을 출력한다.

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

VCPP, GPP에서 사용

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

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		/*

		알고리즘이 들어가는 부분

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

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}