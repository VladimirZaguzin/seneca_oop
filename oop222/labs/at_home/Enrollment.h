
#ifndef SICT_ENROLLMENT_H_
#define SICT_ENROLLMENT_H_

namespace sict{


	class Enrollment{
	private:
		char _name[31];
		char _code[11];
		int _year;
		int _semester;
		int _slot;
		bool _enrolled;
	public:
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);


		Enrollment();
		Enrollment(const char* name, const char* code, int year, int time, int semester);

		bool hasConflict(const Enrollment &other) const;
		void display(bool nameOnly = false)const;
		bool valid()const;
		void setEmpty();
		bool isEnrolled() const;
		void set(const char* name, const char* code, int year, int time, int semester, bool enrolled = false);


	};
}
#endif