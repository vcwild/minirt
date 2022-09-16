/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:26:30 by vwildner          #+#    #+#             */
/*   Updated: 2022/09/16 17:43:04 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/**
 * @brief A list of nodes with content.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
 * @brief fills the first n bytes of the memory
 * area pointed to by s with the constant byte c.
 *
 * @param s Pointer of memory area
 * @param c Constant byte to fill memory area
 * @param n Number of bytes to fill
 * @return void* Returns a pointer to the memory area s
 */
void		*ft_memset(void *s, int c, size_t n);

/**
 * @brief Set n bytes of s to 0.
 *
 * @param s Pointer to the start of the memory location
 * @param n Buffer size
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * @param dest	Destination pointer of memory area
 * @param src	Source pointer of memory area
 * @param n		Buffer size in bytes
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies no more than n bytes
 * from memory area src to memory area dest, stopping
 * when the character c is found.
 *
 * @param dest Destination pointer of memory area
 * @param src Source pointer of memory area
 * @param c Character to be searched
 * @param n Buffer size
 * @return void* Returns pointer to the next character in dest after c,
 * or NULL if c was not found in the first n characters of src.
 */
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * @brief Copies n bytes from memory
 * area src to memory area dest.
 *
 * @param dest	Destination pointer of memory area
 * @param src	Source pointer of memory area
 * @param n		Buffer size in bytes
 * @return void* Returns a pointer to dest.
 */
void		*ft_memmove(void *dest, const void *src, size_t len);

/**
 * @brief Scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c
 *
 * @param s Pointer to the initial memory area
 * @param c Character to be searched
 * @param n Buffer size
 * @return	Return a pointer str to the matching byte
 * or NULL if it does not occur
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief compares the first n bytes (each interpreted
 * as unsigned char) of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area to be compared
 * @param s2 Pointer to the second memory area to be compared
 * @param n Buffer size in bytes
 * @return int Returns an integer less than, equal
 * to, or greater than zero if the first n bytes of s1 is
 * found, respectively, to be less than, to match, or be
 * greater than the first n bytes of s2.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief calculates the length of the string
 * pointed to by s, excluding the terminating null byte ('\0').
 *
 * @param s Pointer to the initial area of the string
 * @return size_t Returns the number of bytes in the
 * string pointed to by s.
 */
size_t		ft_strlen(const char *s);

/**
 * @brief Returns a pointer to a new string
 * which is a duplicate of the string s.
 *
 * @param s1 Pointer to the start of the string do be copied
 * @return char* On success, returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory
 * was available, with errno set to indicate the cause of the
 * error.
 */
char		*ft_strdup(const char *s1);

/**
 * @brief Copies up to size - 1 characters from
 * the NUL-terminated string src to dst, NUL-terminating the result.
 *
 * @param dst	Pointer to the destination area of memory
 * @param src	Pointer to the source area of memory
 * @param size	Buffer size in bytes
 * @return size_t Returns the length of src.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated
 * string src to the end of dst.  It will append at most
 * size - strlen(dst) - 1 bytes, NUL-terminating the result.
 *
 * @param dest	Pointer to the destination area of memory
 * @param src	Pointer to the source area of memory
 * @param size	Buffer size in bytes
 * @return size_t Return the total length of the string,
 * that is the initial length of dst plus the length of src.
 */
size_t		ft_strlcat(char *dest, char *src, size_t size);

/**
 * @brief Returns a pointer to the
 * first occurrence of the character c in the string s.
 *
 * @param s Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* Return a pointer to the matched character
 * or NULL if the character is not found.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Finds the end of the string `s`, then returns
 * a pointer to the first occurrence of the character
 * `c` in the string `s` by iterating backwards.
 *
 * @param s Pointer to the string memory area
 * @param c Character to be searched inside the string s
 * @return char* Return a pointer to the matched character
 * or NULL if the character is not found.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Locates the first occurrence of the null-terminated
 * string little in the string big, where not more than `len` characters
 * are searched. Characters that appear after a `\\0` character are not
 * searched.
 *
 * @param big		String to be searched by `little`
 * @param little	String to search in `big`
 * @param len		Number of bytes to search
 * @return char* If little is an empty string, big is returned.
 * If little occurs nowhere in big, NULL is returned.
 * otherwise a pointer to the first character of the first occurrence
 * of little is returned.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Compares the two strings s1 and s2.
 * The locale is not taken into account
 *
 * @param s1 Pointer to the area of memory of the first string
 * @param s2 Pointer to the area of memory of the second string
 * @param n Buffer size in bytes to compare both strings
 * @return int Return an integer less
 * than, equal to, or greater than zero if s1 (or the first n
 * bytes thereof) is found, respectively, to be less than, to
 * match, or be greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief converts the initial portion of the string pointed
 * to by nptr to int.
 *
 * @param nptr Pointer to the area of memory of the string
 * to be converted
 * @return int The converted value or 0 on error
 */
int			ft_atoi(const char *str);

/**
 * @brief Verifies if the character c is alphabetic.
 *
 * @param c Character to be analysed
 * @return int Returns true if c is alphabetical, else returns false.
 */
int			ft_isalpha(int c);

/**
 * @brief Verifies if the character c is a number.
 *
 * @param c Character to be verified
 * @return int Returns true if c is a number, else returns false.
 */
int			ft_isdigit(int c);

/**
 * @brief Verifies if the character c is alphanumeric.
 *
 * @param c Character to be verified
 * @return int Returns 1 if c is alphanumeric, else returns 0.
 */
int			ft_isalnum(int c);

/**
 * @brief Verify if the character typed is from the ASCII table.
 *
 * @param c Character to be analysed
 * @return int Retuns 1 if character is found, and 0 if not found.
 */
int			ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 *
 * @param c Character to be checked
 * @return int Returns 1 if character is printable, else returns 0.
 */
int			ft_isprint(int c);

/**
 * @brief Converts uppercase character to lowercase.
 *
 * @param c Character to be converted
 * @return int Returns converted lowercase character.
 */
int			ft_tolower(int c);

/**
 * @brief Converts lowercase character to uppercase.
 *
 * @param c Character to be converted
 * @return int Returns converted uppercase character.
 */
int			ft_toupper(int c);

/**
 * @brief Allocates memory for an array
 * of nmemb elements of size bytes each and returns
 * a pointer to the allocated memory. The memory
 * is set to zero.
 *
 * @param nmemb	Number of elements in array
 * @param size	Size of bytes for each element
 * @return void* Return a pointer to the
 * allocated memory, which is suitably aligned for any built-in
 * type. On error, these functions return NULL. NULL may also
 * be returned by a successful call but with size 0.
 */
void		*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
 * The substring begins at index ’start’ and is ofmaximum size ’len’.
 *
 * @param s		The string from which to create the substring.
 * @param start	The start index of the substring in the string’s’.
 * @param len	The maximum length of the substring.
 * @return char* Returns the substring. NULL if the allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a newstring,
 * which is the result of the concatenationof ’s1’ and ’s2’.
 *
 * @param s1 The prefix string
 * @param s2 The suffix string
 * @return char* Returns the new string or NULL if the allocation fails.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns
 * a copy of ’s1’ with the characters specified
 * in ’set’ removed from the beginning and the
 * end of the string.
 *
 * @param s1 The string to be trimmed
 * @param set The set of characters to trim
 * @return char* Returns the trimmed string,
 * or NULL if allocation fails.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 *
 * @param s The string to be split
 * @param c The delimiter character
 * @return char** Returns a matrix of two splitted arrays,
 * else returns NULL if allocation fails.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n The integer to convert
 * @return char* Returns the string representing the integer.
 * NULL if the allocation fails.
 */
char		*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’
 * to create a new string (with malloc(3)) resulting from successive
 * applications of ’f’.
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each characte
 * @return char* The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Outputs the character ’c’ to the given filedescriptor.
 *
 * @param c The character to output
 * @param fd The file descriptor on which to write
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given filedescriptor.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void		ft_putstr_fd(char const *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given filedescriptor,
 * followed by a newline.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given filedescriptor.
 *
 * @param n The integer to output
 * @param fd The file descriptor on which to write
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates (with malloc(3)) and returns a new element.
 * The variable ’content’ is initialized with the value of the
 * parameter ’content’. The variable ’next’ is initialized to NULL.
 *
 * @param content The content to create the new element with
 * @return t_list* The new element
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be added to the list
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of a list
 * @return int Returns the length of a list
 */
int			ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list
 * @return t_list* Returns the last element of the list.
 * Returns NULL if `lst` is empty
 * or is already in the last element.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the `new` element at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be
 * added to the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the
 * memory of the element’s content using the function
 * ’del’ given as a parameter and free the element.
 * The memory of ’next’ must not be freed.
 *
 * @param lst The element to free
 * @param del The address of the function used to delete the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Deletes and frees the given element and every
 * successor of that element, using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param lst The adress of a pointer to an element
 * @param del The adress of the function used to delete
 * the content of the element.
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ to the content of each element.
 *
 * @param lst The adress of a pointer to an element
 * @param f The adress of the function used to iterate on the list
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’
 * to the content of each element. Creates a new list resulting
 * of the successive applications of the function ’f’.
 * The ’del’ function is used to delete the content of an element if needed.
 *
 * @param lst	The adress of a pointer to an element
 * @param f		The adress of the function used to iterate on the list
 * @param del	The adress of the function used to delete the
 * content of an element if needed
 * @return t_list* Returns the new list or NULL if the allocation fails.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Reallocates the memory of the given string to the given size.
 *
 * @param ptr The adress of the string to reallocate
 * @param size The size of the new memory
 * @return void* Returns the adress of the new memory
 */
void		*ft_realloc(void *ptr, size_t size);

/**
 * @brief Frees a matrix of a given vector size.
 *
 * @param matrix The matrix to be freed.
 */
void		free_matrix(char **matrix);

/**
 * @brief Swaps the values of two pointers.
 *
 * @param a The first pointer.
 * @param b The second pointer.
 * @param size The size of bytes to swap.
 */
void		ft_swap(void *a, void *b, size_t size);

double		ft_atof(const char *str);

int			ft_isspace(char c);

int			ft_isfloat(char *str);

/**
 * @brief Sends the string ’s’ to the standard error fd.
 *
 * @param s The string to output
 */
void		ft_err(char const *s);
#endif
