using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using UnrealSharp;
using UnrealSharp.Attributes;
using UnrealSharp.CoreUObject;
using UnrealSharp.Engine;
using UnrealSharp.EnhancedInput;

namespace ManagedTeamProject.Character
{
    [UClass]
    public class ABaseCharacter : ACharacter
    {
        [UProperty(PropertyFlags.EditAnywhere | PropertyFlags.BlueprintReadWrite)] public float BaseSpeed { get; set; } = 600f;



        public ABaseCharacter()
        {
            CharacterMovement.SetPlaneConstraintFromVectors(new FVector(0, 1, 0), new FVector(0, 0, 1));
        }

        protected override void BeginPlay()
        {
            base.BeginPlay();

        }

        public override void Tick(float deltaSeconds)
        {
            base.Tick(deltaSeconds);
        }

    }
}
