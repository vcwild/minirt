#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 128
#define MAX_TABLE_SIZE 10
#define DELETED_NODE (t_person *)(0xFFFFFFFF)

typedef struct s_person {
	char name[MAX_ARR_SIZE];
	int age;
} t_person;

t_person **get_table(void)
{
	static t_person *table[MAX_TABLE_SIZE];

	return (table);
}

void init_table(void)
{
	int i;
	t_person **table;

	i = 0;
	table = get_table();
	while (i < MAX_TABLE_SIZE)
	{
		table[i] = NULL;
		i++;
	}
}

unsigned int hashmap_function(unsigned int key)
{
	/* Robert Jenkins' 32 bit Mix Function */
	key += (key << 12);
	key ^= (key >> 22);
	key += (key << 4);
	key ^= (key >> 9);
	key += (key << 10);
	key ^= (key >> 2);
	key += (key << 7);
	key ^= (key >> 12);
	/* Knuth's Multiplicative Method */
	key = (key >> 3) * 2654435761;

	return (key % MAX_TABLE_SIZE);
}

unsigned int hash_function(char *str)
{
	unsigned int hash;
	int i;

	hash = 0;
	i = -1;
	while (str[++i])
	{
		hash += str[i];
		hash = (hash * str[i]) % MAX_TABLE_SIZE;
	}
	return (hashmap_function(hash));
}

int insert_person(t_person *person) {
	int index;
	int i;
	int try;
	t_person **table;

	if (person == NULL)
		return (-1);
	index = hash_function(person->name);
	table = get_table();
	i = -1;
	while(i < MAX_TABLE_SIZE)
	{
		try = (++i + index) % MAX_TABLE_SIZE;
		if (table[try] == NULL || table[try] == DELETED_NODE)
		{
			table[try] = person;
			printf("%s inserted at index %d\n", person->name, try);
			return (try);
		}
	}
	printf("Could not insert %s\n", person->name);
	return (-1);
}

int delete_person(char *name) {
	int index;
	int try;
	int i;
	t_person **table;

	index = hash_function(name);
	table = get_table();
	i = -1;
	while (i < MAX_TABLE_SIZE)
	{
		try = (++i + index) % MAX_TABLE_SIZE;
		if (table[try] == NULL)
			break;
		if (table[try] == DELETED_NODE)
			continue;
		if (strcmp(table[try]->name, name) == 0)
		{
			table[try] = DELETED_NODE;
			printf("Person deleted at index %d\n", try);
			return (try);
		}
	}
	printf("Could not delete %s\n", name);
	return (-1);
}

void inspect_person(t_person *person) {
	printf(".name: %s\t.age: %d\n", person->name, person->age);
}

void inspect_table(void) {
	t_person **table;

	printf("--------\n");
	table = get_table();
	for (int i = 0; i < MAX_TABLE_SIZE; i++)
	{
		if (table[i] && (table[i] != DELETED_NODE))
		{
			printf("table[%d] = ", i);
			inspect_person(table[i]);
		}
		else if (table[i] == DELETED_NODE)
		{
			printf("table[%d] = 0xFFFFFFFF\n", i);
		}
		else
		{
			printf("table[%d] = NULL\n", i);
		}
	}
	printf("--------\n");
}

int find_person(char *name) {
	int index;
	int try;
	int i;
	t_person **table;

	index = hash_function(name);
	table = get_table();
	i = -1;
	while (i < MAX_TABLE_SIZE)
	{
		try = (++i + index) % MAX_TABLE_SIZE;
		if (table[try] == NULL)
			break;
		if (table[try] == DELETED_NODE)
			continue;
		if (strcmp(table[try]->name, name) == 0)
		{
			printf("Person found at index %d\n", try);
			return (try);
		}
	}
	printf("%s not found!!\n", name);
	return (-1);
}

int main(void) {
	int i;
	init_table();

	t_person john = {.name="John", .age=25};
	t_person jane = {.name="Jane", .age=30};
	t_person jack = {.name="Jack", .age=35};
	t_person jill = {.name="Jill", .age=40};
	t_person joe = {.name="Joe", .age=45};
	t_person jim = {.name="Jim", .age=50};
	t_person jem = {.name="Jem", .age=55};
	t_person jan = {.name="Jan", .age=60};
	t_person jak = {.name="Jak", .age=65};
	t_person jon = {.name="Jon", .age=70};

	t_person *people[] = {&john, &jane, &jack, &jill, &joe, &jim, &jem, &jan, &jak, NULL};

	i = -1;
	while (people[++i])
		insert_person(people[i]);

	inspect_table();
	delete_person("Jak");
	find_person("Jak");
	insert_person(&jak);
	find_person("Jak");
	delete_person("Jim");
	find_person("Jim");
	delete_person("John");
	delete_person("John");
	delete_person("Jack");
	delete_person("Joe");
	inspect_table();

	return (0);
}
