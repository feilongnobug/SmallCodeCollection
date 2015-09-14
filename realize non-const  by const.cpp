//effective c++
class TextBlock{
public:
    const char& operator[](std::size_t position) const
    {
    //bounds checking
    //log access data
    //verify data integrity
    //...
    return text[position];
    }

    char& operator[](std::size_t position){
        return
            const_cast<char&>(
                static_cast<const TextBlock&>(*this)[position]
                              );
    }
private:
    std::string text;
};

