#include <iostream>
class Smart_array
{
	private:
		const char* m_out_message = "out of the range";
		int m_default_value = 0;
		int m_size;
		int* m_array;
		bool init();
		bool is_out(unsigned int);
		bool is_out(unsigned int) const;
		void move(int*, int*, unsigned int, unsigned int);
	public:
		/**
		 *@brief Smart_array constructor.
		 *@detail Creates a float array with the given size,
		 *   initializes it with default values.
		 *@param unsigned int The size of the m_array.
		 *@param int the default values for initialization
		 *@return void.
		 */
		Smart_array(unsigned int, int);
		/**
		 *@brief Smart_array copy constructor.
		 *@param  a refferenc to const Smart_array.
		 *@return void.
		 */
		Smart_array(const Smart_array &s);
		/**
		 *@brief Smart_array destructor.
		 *@return void.
		 */
		~Smart_array();
		/**
		 *@brief Smart_array setter function.
		 *@detail Sets the given value to the given index, if the index
		 *    is valid.
		 *@param int the index.
		 *@param int the value.
		 *@return bool true if the value is set, false otherwise.
		 */
		bool set_element(unsigned int, int);
		/**
		 *@brief Resizes the array .
		 *@detail sets the array size to the given value, if the new
		 *    array size is bigger than the old one , added cells are
		 *    initialized to "empty" value, else the cells that get out
		 *    of range are cut off.
		 *@param int the new size of the array.
		 *@return void.
		 */	
		void resize(unsigned int);
		/**
		 *@brief gets the value of the element with the given index .
		 *@param int the index.
		 *@return value, if the cell exists and m_default_value otherwise.
		 */
		int get_element(unsigned int);
		/**
		 *@brief returns the size of the current array
		 *@return int the size of the current array
		 */
		const int get_size() const;
		int get_size();
		/**
		 * @brief prints the current array
		 */
		void print_array();
		/**
		 *@brief swaps the values of given cells .
		 *@param unsigned int the index.
		 *@param unsigned int the index
		 *@return true if the swap was sucessfull , false otherwise.
		 */
		bool swap (unsigned int,unsigned int);
		/**
		 *@brief operator[] overloader.
		 *@detial returns the element with a given index or sets th
		 *	e value to the given index;
		 *@param unsigned int the index;
		 *@return int& reference to the element;
		 */
		int& operator[](unsigned int);
		/**
		 *@brief operator[] overloader for const objects.
		 *@detial returns the element with a given index.
		 *@param unsigned int the index;
		 *@return const int& reference to the element;
		 */
		const int& operator[](unsigned int) const;
		/**
		 *@brief operator<< overloader.
		 *@detail prints the given object.
		 *@param std::ostream&
		 *@param const Smart_array&
		 *@return void
		 */
		friend std::ostream& operator<<(std::ostream& ,const
				Smart_array&);
		/**
		 * @brief operator= overloader;
		 * @param Smart_array&
		 * return Smart_array&
		 */
		Smart_array& operator=(const Smart_array& s);
};
