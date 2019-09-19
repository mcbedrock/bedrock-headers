#pragma once

struct Certificate {

};

struct ExtendedCertificate : Certificate {
	static std::string getXuid(Certificate const &);
};