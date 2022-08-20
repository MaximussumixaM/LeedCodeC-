#include <iostream>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

//Идея заключается в следующем :
//
//Сначала установите перенос, чтобы указать, что две цифры в определенной цифре должны содержать 1, если сумма больше 9, а начальное значение равно 0.
//Затем, пока число на узле двух чисел не равно 0 одновременно, оно будет продолжать считывать число, проходя узлы двух односвязных списков из младшего бита, чтобы прочитать число.После этого нет необходимости читать задний узел этого односвязного списка : если он не равен 0, он присваивается n, а затем добавляются два n и перенос переноса, чтобы получить сумму цифр в определенной позиции.
//Затем разделите на 10, чтобы определить, переносить ли > 10 = 1, иначе 0.
//В то же время, пленка 10 используется для получения числа на бите после добавления, и новый узел добавляется к текущему узлу.
//Перед завершением цикла переместите три связанных списка, запомнитеСначала установите следующий, затем укажите текущий на следующий。
//Наконец, прежде чем возвращать следующий указатель результата, не забудьте оценить, есть ли значение в переносе или его нужно переносить.

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head;
        ListNode* temp = &head;
        while (l1 || l2) {
            int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = val / 10;
            temp->next = new ListNode(val % 10);
            temp = temp->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
            temp->next = new ListNode(carry);
        return head.next;
    }
};

int main()
{
	ListNode* head1 = NULL;
	ListNode* one1 = NULL;
	ListNode* two1 = NULL;

	// allocate 3 nodes in the heap
	head1 = new ListNode(2);
	one1 = new ListNode(4);
	two1 = new ListNode(3);

	// Connect nodes
	head1->next = one1;
	one1->next = two1;
	two1->next = NULL;

	ListNode* head2 = NULL;
	ListNode* one2 = NULL;
	ListNode* two2 = NULL;


	// allocate 3 nodes in the heap
	head2 = new ListNode(5);
	one2 = new ListNode(6);
	two2 = new ListNode(4);

	// Connect nodes
	head2->next = one2;
	one2->next = two2;
	two2->next = NULL;


	ListNode* result = Solution::addTwoNumbers(head1, head2);
	std::string str_result = "";
	while (result != NULL) {
		//std::cout << result->val;
		str_result += std::to_string(result->val);
		result = result->next;
	}

	if (str_result == "708") {

		std::cout << "Test Access";
	}
	else {
		std::cout << "Test Denied";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
