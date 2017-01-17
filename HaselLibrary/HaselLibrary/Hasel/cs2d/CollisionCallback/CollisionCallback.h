#pragma once

#include"../Hasel/HaselAlias.h"
#include"../Hasel/math/MathInc.h"

#include<functional>
#include<vector>

namespace hasel
{
	namespace shape
	{
		class ShapeBase;
	}

	namespace cs2d
	{
		class RigidBody;
		using CallbackFunction = std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&)>;

		/// <summary>
		/// 衝突したときに呼ばれる処理を登録するクラス
		/// </summary>
		class Callback
		{
		public:
			struct CollisionInfo
			{
				std::vector<shape::ShapeBase*> collideShapeA;
				std::vector<shape::ShapeBase*> collideShapeB;
				math::Vector2 inter;
			};
		private:
			static unsigned long long ConstructionCount;

			//衝突する剛体の属性A
			int attributeA;
			//衝突する剛体の属性B
			int attributeB;
			//コールバック
			std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&,const CollisionInfo& info)> callback;
			//ユニーク番号
			unsigned long long uniqueNum;

		public:

			/// <summary>
			/// コンストラクタ
			/// </summary>
			/// <param name="attributeA">衝突させる剛体の属性A</param>
			/// <param name="attributeB">衝突させる剛体の属性B</param>
			/// <param name="callback">衝突時に呼び出す関数</param>
			Callback(int attributeA, int attributeB, 
				const std::function<void(const wptr<RigidBody>&, const wptr<RigidBody>&,const CollisionInfo&)>& callback);

			/// <summary>
			/// 剛体Aの属性を取得
			/// </summary>
			/// <returns>属性</returns>
			int GetAttributeA()const;

			/// <summary>
			/// 剛体Bの属性を取得
			/// </summary>
			/// <returns>属性</returns>
			int GetAttributeB()const;

			/// <param name="bodyA">衝突した剛体A</param>
			/// <param name="bodyB">衝突した剛体B</param>
			void operator()(const wptr<RigidBody>& bodyA, const wptr<RigidBody>& bodyB,const CollisionInfo& info)const;

			/// <param name="rhs">比較する値</param>
			/// <returns></returns>
			bool operator==(const Callback& rhs)const;
		};

	}
}