



  class Enrollment{
  private:
    char _name[31];
    char _code[11];
    int _year;
    int _semester;
    int _slot;
    bool _enrolled;
  public:


    void display(bool nameOnly = false)const;
    bool valid()const;
    void setEmpty();
    bool isEnrolled() const;
  };
