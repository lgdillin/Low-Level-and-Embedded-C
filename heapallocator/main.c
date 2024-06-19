#include <Windows.h>
#include <heapapi.h>

#include <stdio.h>

struct MyStruct {
	int x;
	int y;
	int z;
};

int s() {

	return 0;
}

int main() {
	HANDLE def_heap = GetProcessHeap();
	HANDLE heap = HeapCreate(0, 0, 4096);

	LPVOID alloc = HeapAlloc(def_heap, HEAP_NO_SERIALIZE, 512);
	if (alloc == NULL) printf("allocation failed\n");
	
	struct MyStruct *m = (struct MyStruct *)(alloc);
	printf("size of MyStruct: %i \n", sizeof(struct MyStruct));

	m->x = 1;
	m->y = 2;
	m->z = 3;

	printf("m: %i ", m->x);
	printf("%i ", m->y);
	printf("%i\n", m->z);


	struct MyStruct *m1 = (struct MyStruct *)(alloc);
	m1->x = 7;
	m1->y = 8;
	m1->z = 9;

	printf("m1: %i ", m1->x);
	printf("%i ", m1->y);
	printf("%i\n", m1->z);

	m->x = 1;
	printf("m1: %i \n", m1->x);

	//
	//
	//
	BOOL freed = HeapFree(def_heap, HEAP_NO_SERIALIZE, alloc);
	if (freed == TRUE) printf("properly freed\n");
	printf("%i", sizeof(alloc));

	return 0;
}