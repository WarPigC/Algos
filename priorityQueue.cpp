#include <initializer_list>
#include <iostream>
#include <vector>
#include <queue>

/*
 *
 *	insertion: O(log n)
 *	deletion: O(log n)
 *	look up (max/min): O(1)
 *	
 *	heapify (or build heap): O(n)			( advantage over BST where it takes O(n log n) )
 *	heapify is an optimized method of building heaps where it takes linear time comp
 *
 */


class Heap{
	private:
		std::vector<int>* heap = new std::vector<int>{0};

		void heapify(std::vector<int>& arr){
			arr.push_back(arr[0]);
			*heap = arr;
			int cur = (heap->size() - 1) / 2;

			while (cur > 0){
				int i = cur;

				// just like pop()
				percolateDown(i);
				--cur;
			}

		}
		void percolateDown(int i){
			while (2 * i < heap->size()){
				if (2 * i + 1 < heap->size() &&
						heap->at(2 * i + 1) < heap->at(2 * i) &&
						heap->at(i) > heap->at(2 * i + 1)){

					// swap right child

					std::swap(heap->at(i), heap->at(2 * i + 1));
					i = 2 * i + 1;
				}

				else if (heap->at(i) > heap->at(2 * i)){
					std::swap(heap->at(i), heap->at(2 * i));
					i *= 2;
				}
				else{
					break;
				}
			}
		}


	public:
		Heap() = default;
		Heap(int i){
			heap->push_back(i);
		}
		Heap(std::vector<int> list){
			heapify(list);
		}

		int size() {return heap->size();}


		void push(int val){
			heap->push_back(val);
			int i = heap->size() - 1;

			// percolate up
			
			while (heap->at(i) < heap->at(i / 2) && i > 0){
				std::swap(heap->at(i), heap->at(i / 2));
				i /= 2;
			}
		}


		int pop(){
			if (heap->size() == 0) return -1;

			else if (heap->size() <= 2){
				int t = heap->at(heap->size() - 1);
				heap->pop_back();
				return t;
			}

			int res = heap->at(1);
			heap->at(1) = heap->at(heap->size() - 1);
			heap->pop_back();

			// percolate down
			int i = 1;
			percolateDown(i);

			return res;
		}



		~Heap(){
			delete heap;
		}

		void display(){
			auto it = heap->begin() + 1;
			while (it != heap->end()){
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}
};

int main(){

	Heap obj;
	obj.push(2);
	obj.push(4);
	obj.push(6);
	obj.push(0);
	obj.push(9);
	obj.push(5);

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(0);
	q.push(9);
	q.push(5);

	q.pop();
	obj.pop();
	q.pop();
	obj.pop();

	obj.display();

	while (!q.empty()){
		int temp = q.top();
		q.pop();
		std::cout << temp << " ";
	}
	std::cout << std::endl;


	// heapify / build heap

	Heap obj2 (*(new std::vector<int> {1, 2, 3}));
	obj2.display();
}
