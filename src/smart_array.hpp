class Smart_array
{
	private:
		const int m_empty_return = 0;
		const char* m_out_message = "out of the range";
		const float m_default_value = 0.5;
		int m_size;
		float* m_array;
		bool init();
		bool is_out(unsigned int);
		void move(float*, float*, int, int);
	public:
		/**
		 *@brief Smart_array constructor.
		 *@detail Creates a float array with the given size, initializes
		 *	it with empty values.
		 *@param unsigned int The size of the m_array.
		 *@return void.
		 */
		Smart_array(unsigned int);
		/**
		 *@brief Smart_array copy constructor.
		 *@param  a refferenc to const Smart_array.
		 *@return void.
		 */
		Smart_array(const Smart_array &s);
		/**
		 *@brief Smart_array setter function.
		 *@detail Sets the given value to the given index, if the index
		 *    is valid.
		 *@param int the index.
		 *@param int the value.
		 *@return bool true if the value is set, false otherwise.
		 */
		bool set_element(int, int);
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
		 *@brief checks if the accessed cell is empty .
		 *@detail checks if the given cell is in the range of array
		 *    size and is empty.
		 *@param int the index.
		 *@return true, if the cell exists and is empty, false otherwise.
		 */	
		bool is_empty(int);
		/**
		 *@brief checks if the accessed cell is empty .
		 *@detail checks if the given cell is in the range of array
		 *    size and is empty.
		 *@param int the index.
		 *@return true, if the cell exists and is empty, false otherwise.
		 */
		int get_element(int);
		/**
		 *@brief returns the size of the current array
		 *@return int the size of the current array
		 */
		int get_size();
		/**
		 * @brief prints the current array
		 */
		void print_array(); 
};
