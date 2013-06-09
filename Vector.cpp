class IndexOutofBounds {};

template <typename T> 
class Vector {
public:
	Vector();		// create an empty vector
	Vector(int size);	// create a vector of size elements
	Vector(const Vector& r);	// copy ctor
	virtual ~Vector();
	T& operator[](int index) : throw(IndexOutofBounds);
		// return the specified element, throws exception when index <0 or >=m_nSize
	int size();		// return the size of the vector
	int inflate(int addSize);	// expand the storage to m_nSize+addSize, return the new size
private:
	T *m_pElements;
	int m_nSize;
};

template <typename T>
Vector<T>::Vector() {
	m_nSize = 0;
};

template <typename T>
Vector<T>::Vector (int size) : m_nSize(size) {
	T *m_pElements = new T[size];	
};

template <typename T>
Vector<T>::Vector (const Vector& r) {
	m_nSize = r.size();
	for (int i = 0; i < m_nSize; i++) {
			
	}
};

template <typename T>
T& operator[](int index): throw(IndexOutofBounds) {
	try {
		if (index < 0 || index > m_nSize)
		throw excep;
		else {
			return *(m_pElements + index);
		}
	}
	catch (exception &ex) {
		cout << "Index out of bound\n";
	}
}

template <typename T>
int Vector<T>::size() {
	return m_nSize;
}
