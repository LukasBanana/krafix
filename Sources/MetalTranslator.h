#pragma once

#include "CStyleTranslator.h"

namespace krafix {
	class MetalTranslator : public CStyleTranslator {
	public:
		MetalTranslator(std::vector<unsigned>& spirv, EShLanguage stage) : CStyleTranslator(spirv, stage) {}
		void outputCode(const Target& target, const char* filename, std::map<std::string, int>& attributes);
		void outputInstruction(const Target& target, std::map<std::string, int>& attributes, Instruction& inst);
	protected:
		const char* builtInName(spv::BuiltIn builtin);
		const char* builtInTypeName(spv::BuiltIn builtin, Type& type);

		std::string name;
		std::string positionName = "position";
	};
}
